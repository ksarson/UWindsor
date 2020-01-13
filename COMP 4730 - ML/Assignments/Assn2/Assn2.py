import sys
import warnings

if not sys.warnoptions:
    warnings.simplefilter("ignore")

import pandas as pd
import matplotlib.pyplot as plt
from sklearn.cluster import KMeans
from sklearn import mixture
from sklearn.cluster import SpectralClustering

#Array of all datasets to be handled
dsf = ['circles0.3.csv', 'halfkernel.csv', 'moons1.csv',
                'spiral1.csv', 'twogaussians33.csv', 'twogaussians42.csv']

#Loop through all datasets provided
for ds in dsf:
    df = pd.read_csv('./SampleDatasets/'+ds)
    X = df.loc[:, df.columns!='label'].values
    kmeans = KMeans(n_clusters=2, random_state=0).fit(X)
    em = mixture.GaussianMixture(n_components=2).fit(X)
    emlabels_ = em.predict(X)
    spectralrbf = SpectralClustering(n_clusters=2, affinity='rbf').fit(X)
    spectralnn = SpectralClustering(n_clusters=2, affinity='nearest_neighbors').fit(X)

    #Accounting for spiral1.csv having different column labels
    if ds == 'spiral1.csv':
        kmeansds = {"x":df["x"], "y":df["y"], "labelold":df.label, "labelnew":kmeans.labels_}
        kmeansdf = pd.DataFrame(kmeansds)
        emds = {"x":df["x"], "y":df["y"], "labelold":df.label, "labelnew":emlabels_}
        emdf = pd.DataFrame(emds)
        spectralrbfds = {"x":df["x"], "y":df["y"], "labelold":df.label, "labelnew":spectralrbf.labels_}
        spectralrbfdf = pd.DataFrame(spectralrbfds)
        spectralnnds = {"x":df["x"], "y":df["y"], "labelold":df.label, "labelnew":spectralnn.labels_}
        spectralnndf = pd.DataFrame(spectralnnds)
    #Accounts for all other .csv files having the same naming convention for columns
    else:
        kmeansds = {"x":df["x1"], "y":df["x2"], "labelold":df.label, "labelnew":kmeans.labels_}
        kmeansdf = pd.DataFrame(kmeansds)
        emds = {"x":df["x1"], "y":df["x2"], "labelold":df.label, "labelnew":emlabels_}
        emdf = pd.DataFrame(emds)
        spectralrbfds = {"x":df["x1"], "y":df["x2"], "labelold":df.label, "labelnew":spectralrbf.labels_}
        spectralrbfdf = pd.DataFrame(spectralrbfds)
        spectralnnds = {"x":df["x1"], "y":df["x2"], "labelold":df.label, "labelnew":spectralnn.labels_}
        spectralnndf = pd.DataFrame(spectralnnds)

    #Figure 1
    plt.figure(1)
    ax = kmeansdf[(kmeansdf.labelnew==0)&(kmeansdf.labelold==0)]
    bx = kmeansdf[(kmeansdf.labelnew==0)&(kmeansdf.labelold==1)]
    cx = kmeansdf[(kmeansdf.labelnew==1)&(kmeansdf.labelold==0)]
    dx = kmeansdf[(kmeansdf.labelnew==1)&(kmeansdf.labelold==1)]
    plt.scatter(ax.x.values, ax.y.values, marker="+", c="c", label="Class 0/Cluster 1")
    plt.scatter(bx.x.values, bx.y.values, marker="+", c="m", label="Class 1/Cluster 1")
    plt.scatter(cx.x.values, cx.y.values, marker="o", c="c", label="Class 0/Cluster 2")
    plt.scatter(dx.x.values, dx.y.values, marker="o", c="m", label="Class 1/Cluster 2")
    plt.title("KMEANS - "+ds)
    plt.legend()

    #Figure 2
    plt.figure(2)
    ax = emdf[(emdf.labelnew==0)&(emdf.labelold==0)]
    bx = emdf[(emdf.labelnew==0)&(emdf.labelold==1)]
    cx = emdf[(emdf.labelnew==1)&(emdf.labelold==0)]
    dx = emdf[(emdf.labelnew==1)&(emdf.labelold==1)]
    plt.scatter(ax.x.values, ax.y.values, marker="+", c="c", label="Class 0/Cluster 1")
    plt.scatter(bx.x.values, bx.y.values, marker="+", c="m", label="Class 1/Cluster 1")
    plt.scatter(cx.x.values, cx.y.values, marker="o", c="c", label="Class 0/Cluster 2")
    plt.scatter(dx.x.values, dx.y.values, marker="o", c="m", label="Class 1/Cluster 2")
    plt.title("EM - "+ds)
    plt.legend()

    #Figure 3
    plt.figure(3)
    ax = spectralrbfdf[(spectralrbfdf.labelnew==0)&(spectralrbfdf.labelold==0)]
    bx = spectralrbfdf[(spectralrbfdf.labelnew==0)&(spectralrbfdf.labelold==1)]
    cx = spectralrbfdf[(spectralrbfdf.labelnew==1)&(spectralrbfdf.labelold==0)]
    dx = spectralrbfdf[(spectralrbfdf.labelnew==1)&(spectralrbfdf.labelold==1)]
    plt.scatter(ax.x.values, ax.y.values, marker="+", c="c", label="Class 0/Cluster 1")
    plt.scatter(bx.x.values, bx.y.values, marker="+", c="m", label="Class 1/Cluster 1")
    plt.scatter(cx.x.values, cx.y.values, marker="o", c="c", label="Class 0/Cluster 2")
    plt.scatter(dx.x.values, dx.y.values, marker="o", c="m", label="Class 1/Cluster 2")
    plt.title("SPECTRAL WITH RBF KERNEL - "+ds)
    plt.legend()

    #Figure 4
    plt.figure(4)
    ax = spectralnndf[(spectralnndf.labelnew == 0)&(spectralnndf.labelold == 0)]
    bx = spectralnndf[(spectralnndf.labelnew == 0)&(spectralnndf.labelold == 1)]
    cx = spectralnndf[(spectralnndf.labelnew == 1)&(spectralnndf.labelold == 0)]
    dx = spectralnndf[(spectralnndf.labelnew == 1)&(spectralnndf.labelold == 1)]
    plt.scatter(ax.x.values, ax.y.values, marker="+", c="c", label="Class 0/Cluster 1")
    plt.scatter(bx.x.values, bx.y.values, marker="+", c="m", label="Class 1/Cluster 1")
    plt.scatter(cx.x.values, cx.y.values, marker="o", c="c", label="Class 0/Cluster 2")
    plt.scatter(dx.x.values, dx.y.values, marker="o", c="m", label="Class 1/Cluster 2")
    plt.title("SPECTRAL WITH NN KERNEL - "+ds)
    plt.legend()

    #Display all figures in current loop iteration
    plt.show()

