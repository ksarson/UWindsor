#include <thread>
#include <future>
#include <iomanip>
#include <iostream>

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

  //#error "TODO: Declare a variable called bm of type benchmark<chrono::high_resolution_clock>"
  static benchmark<chrono::high_resolution_clock> bm;
  //#error "TODO: Declare a variable called swsc of type stop_when_stopped_controller."
  static stop_when_stopped_controller swsc;

  //#error "TODO: Write "auto future_result = async("
  auto future_result = async(launch::async, []() {
    bm.start();
    auto result = monte_carlo<tally_predicate>(swsc, []() {
       static thread_local decltype(make_randomly_seeded_mt19937_64_engine()) xre = make_randomly_seeded_mt19937_64_engine();
       static thread_local decltype(make_randomly_seeded_mt19937_64_engine()) yre = make_randomly_seeded_mt19937_64_engine();
       static thread_local uniform_real_distribution<REAL> ud(REAL(0), REAL(1));

       auto x = ud(xre);
       auto y = ud(yre);

       return (x*x + y*y) <= 1;

    });
    return result;
  });
  // where "async(" is the start of a call to std::async;
  // the first argument passed to async is launch::async (this will run the
  // lambda function passed as the second argument in another thread); and,
  // the second argument is a lambda function as follows:
  //   * The lambda captures by reference the variables swsc and bm.
  //   * The lambda has no function arguments.
  //   * The code in the lambda is as follows:
  //     * The first line is "bm.start()" to start the benchmark.
  //     * Copy the "auto result = monte_carlo"... etc. code from Part 1 here.
  //       ENSURE THAT YOU ADD thread_local to each of the 3 static variables!!
  //     * After that, call "bm.stop()" to stop the benchmark.
  //     * Finally "return result;"
  // and close off the lambda and async.

  cout << "Sleeping... ";
  cout.flush();
  this_thread::sleep_for(chrono::seconds(2));

  cout << "stopping... ";
  swsc.stop();
  cout.flush();

//#error "TODO: Call future_result.get() and assign what it returns to the variable called result."
  auto result = future_result.get();
  cout << "Done.\n";
  cout.flush();

  // the next two lines allow one to reset width and precision to their
  // defaults...
  auto const default_cout_width = cout.width();
  auto const default_cout_precision = cout.precision();

  cout
    << "The Monte Carlo method was executed serially "
    << result.count() << " times.\n"
    << "Estimate of pi = "
    << setw(numeric_limits<REAL>::max_digits10)
    << setprecision(numeric_limits<REAL>::max_digits10)
    << REAL(result.true_count()) / REAL(result.count()) * REAL(4)
    << "\nTotal elapsed time = "
    << setw(default_cout_width)
    << setprecision(default_cout_precision)
    << duration_convert(bm.duration()).count()
    << " seconds."
    << endl;
  ;
}
