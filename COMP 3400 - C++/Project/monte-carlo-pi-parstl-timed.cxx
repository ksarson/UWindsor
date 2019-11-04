#include <thread>
#include <future>
#include <iomanip>
#include <iostream>

#include <pstl/execution>
#include <pstl/algorithm>
#include <pstl/numeric>
#include <pstl/memory>

#include "tally-utils.hxx"
#include "random-utils.hxx"
#include "benchmark-utils.hxx"
#include "controller-utils.hxx"
#include "monte-carlo-utils.hxx"

#include "project-tally-task.hxx"

using REAL = long double;

int main()
{
  using namespace std;

  //
  // Method to estimate pi (3.151592...) using Monte Carlo...
  //
  // Given a circle of radius 0.5 enclosed in a unit square:
  //   * area_of_circle = pi * radius**2
  //     i.e., radius == 0.5
  //   * area_of_square = 1
  // Thus, area_of_square / area_of_circle == pi / 4.
  //
  // Generate uniformly distributed random numbers within
  // the square, i.e., [0,1]. Pi is calculated as the number
  // of points in the circle by the total number of points
  // the resulting ratio should approximate pi / 4. Thus,
  // a Monte Carlo estimate of pi would be 4 times pi / 4.
  //

  //#error "NOTE: ninvocations is NOT the number of threads created later!"
  auto const ninvocations = 8;
  cout << "Running " << ninvocations << " invocations... ";
  cout.flush();

  // benchmark the total time to compute everything...
  //#error "TODO: Construct a variable called bm of type benchmark<chrono::high_resolution_clock>"
  benchmark<chrono::high_resolution_clock> bm;
  // NOTE: You can either pass the constructor
  //       benchmark<chrono::high_resolution_clock>::start_clock to start the
  //       benchmark, or, after the declaration call bm.start() to do the same.

  // Use a controller to stop all work after two seconds...
  //#error "TODO: Construct a variable called swsc of type stop_after_duration_controller<chrono::high_resolution_clock>"
  stop_after_duration_controller<chrono::high_resolution_clock> swsc(2s);
  // where you pass 2s to the constructor. (NOTE: "s" is a literal operator
  // definition defined by the C++ standard to make the value before it
  // have the units of "seconds". The value before the literal operator
  // CANNOT be separated by whitespace.) See:
  //   * The beginning of this blog entry:
  //       https://www.preney.ca/paul/archives/636
  //   * https://en.cppreference.com/w/cpp/chrono/duration#Literals

  // Intel Parallel STL requires contiguous, random-access iterators
  // so populate a vector<size_t>...
  vector<size_t> indices(ninvocations);
  iota(begin(indices), end(indices), 0);
  // USE cs340.cs.uwindsor.ca as the Intel Parallel STL library and its
  // prerequisites are already installed there. Links to Intel ParallelSTL
  // materials are:
  //   * https://github.com/intel/parallelstl
  //   * https://software.intel.com/en-us/articles/get-started-with-parallel-stl

  // The C++17 std::transform_reduce() algorithm will be used here to:
  //   * transform (i.e., map) each size_t index to tally_predicate
  //   * reduce (i.e., accumulate) each tally_predicate to a single
  //     tally_predicate
  auto total = transform_reduce(pstl::execution::par_unseq,

  //#error "TODO: arguments 2 & 3: pass iterator range [begin(indices),end(indices))"
    begin(indices), end(indices),
  //#error "TODO: argument 4: pass in default constructed tally_predicate"
    // NOTE: This is the identity element of performing the reduction
    //       i.e., the "sum"/"accumulate" operations.
      tally_predicate{},
  //#error "TODO: argument 5: binary lambda, no captures..."
      [](auto x, auto y) {
        return x + y;
      },
    // NOTE: This lambda is passed two values during the reduction
    //       process: one is the current "sum" of tally_predicates
    //       and the other is a newly available tally_predicate. This
    //       lambda will return the "sum" of these two values.
    //       Use the operator +() function to compute this and return the
    //       result.

  //#error "TODO: argument 6: unary lambda, capture-b-reference swsc"
      [&swsc](size_t const&) {
    // NOTE: This lamba "maps" one of the values in the range
    //       [begin(indices),end(indices)) and uses such to invoke the
    //       monte_carlo function in this project.
    //
    //       In this instance, IGNORE the argument passed in, e.g.,
    //       write "size_t const&" without a variable name. Simply invoke
    //       the monte_carlo function from Part 2 and return the result
    //       from this lambda. (Relative to Part 1's code ensure that
    //       "thread_local" is added to the static variable definitions.)
        auto result = monte_carlo<tally_predicate>(swsc, []() {
       static thread_local decltype(make_randomly_seeded_mt19937_64_engine()) xre = make_randomly_seeded_mt19937_64_engine();
       static thread_local decltype(make_randomly_seeded_mt19937_64_engine()) yre = make_randomly_seeded_mt19937_64_engine();
       static thread_local uniform_real_distribution<REAL> ud(REAL(0), REAL(1));

       auto x = ud(xre);
       auto y = ud(yre);

       return (x*x + y*y) <= 1;

        });
      return result;
      }
  );

  bm.stop();

  // the next two lines allow one to reset width and precision to their
  // defaults...
  auto const default_cout_width = cout.width();
  auto const default_cout_precision = cout.precision();

  cout
    << "The Monte Carlo method was executed using " << ninvocations
    << " invocations with a total of " << total.count() << " samples.\n"
    << "The overall estimate of pi is "
    << setw(numeric_limits<REAL>::max_digits10)
    << setprecision(numeric_limits<REAL>::max_digits10)
    << REAL(total.true_count()) / REAL(total.count()) * REAL(4)
    << "\nTotal elapsed time = "
    << setw(default_cout_width)
    << setprecision(default_cout_precision)
    << duration_convert(bm.duration()).count()
    << " seconds."
    << endl;
  ;
}
