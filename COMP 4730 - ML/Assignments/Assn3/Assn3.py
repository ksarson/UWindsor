#Imports
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.decomposition import PCA
from sklearn.decomposition import KernelPCA
from sklearn.preprocessing import StandardScaler
from sklearn.cluster import KMeans


#PCA Function
def executePCA(df, dim):
    X = df.loc[:, df.columns!="label"]
    y = df.loc[:, df.columns=="label"]
    X_std = StandardScaler().fit_transform(X)
    sk_pca = PCA(n_components=dim)
    X_pca = sk_pca.fit_transform(X_std)

    #Create the PCA dataset
    pca_ds = {}
    for i in range(dim):
        pca_ds["pca"+str(i)] = X_pca[:, i]
    pca_ds["label"] = df.label

    return pd.DataFrame(pca_ds)


#Kernel PCA Function (KPCA)
def executeKPCA(df, dim, kfunc="linear", gvalue=10):
    X = df.loc[:, df.columns!="label"]
    y = df.loc[:, df.columns=="label"]
    X_std = StandardScaler().fit_transform(X)
    sk_kpca = KernelPCA(n_components=dim, kernel=str(kfunc), gamma=gvalue)
    X_kpca = sk_kpca.fit_transform(X_std)

    #Create the KPCA dataset
    kpca_ds = {}
    for i in range(dim):
        kpca_ds["pca"+str(i)] = X_kpca[:, i]
    kpca_ds["label"] = df.label

    return pd.DataFrame(kpca_ds)


#Filenames of datasets to be used
filenames = ['circles0.3.csv', 'halfkernel.csv', 'moons1.csv', 'spiral1.csv']

#Setting k and g values for each dataset
for filename in filenames:
    if filename == 'circles0.3.csv':
        kfunc = 'rbf'
        gvalue = 1
    elif filename == 'halfkernel.csv':
        kfunc = 'rbf'
        gvalue = 3
    elif filename == 'moons1.csv':
        kfunc = 'rbf'
        gvalue = 27
    elif filename == 'spiral1.csv':
        kfunc = 'rbf'
        gvalue = 38

    #Load data then begin plotting
    df = pd.read_csv('./SampleDatasets/'+str(filename))
    df.columns = ['x1', 'x2', 'label']

#PCA
    #Original for PCA
    plt.figure(figsize=(8, 6), dpi=120)
    plt.suptitle('PCA for '+filename, fontsize=16)
    plt.subplot(2, 2, 1, aspect='equal')
    plt.scatter(df.x1[df.label==0], df.x2[df.label==0], marker='+', color='c', alpha=0.5, s=5)
    plt.scatter(df.x1[df.label==1], df.x2[df.label==1], marker='o', color='m', alpha=0.5, s=5)
    plt.title('Original Dataset'), plt.xlabel('x'), plt.ylabel('y')

    #Result after PCA
    pca_df = executePCA(df, dim=2)
    plt.subplot(2, 2, 2, aspect='equal')
    plt.scatter(pca_df.pca0[pca_df.label==0], pca_df.pca1[pca_df.label==0], marker='+', color='c', alpha=0.5, s=5)
    plt.scatter(pca_df.pca0[pca_df.label==1], pca_df.pca1[pca_df.label==1], marker='o', color='m', alpha=0.5, s=5)
    plt.title('Result after PCA'), plt.xlabel('PC1'), plt.ylabel('PC2')

    #Reduction to 1D for PCA
    pca_df = executePCA(df, dim=1)
    plt.subplot(2, 2, 3, aspect=0.5)
    plt.scatter(pca_df.pca0[pca_df.label==0], np.zeros((500,1)), marker='+', color='c', alpha=0.8, s=5)
    plt.scatter(pca_df.pca0[pca_df.label==1], np.zeros((500,1)), marker='o', color='m', alpha=0.8, s=5)
    plt.title('Reduction to 1D'), plt.xlabel('PC1'), plt.ylim(top=1), plt.ylim(bottom=-1)

    #KMeans Clutering for PCA
    features = pca_df.loc[:, pca_df.columns!="label"]
    kmeans = KMeans(n_clusters=2, random_state=0).fit(features)
    pca_df["kmeans_label"] = kmeans.labels_
    plt.subplot(2, 2, 4, aspect=0.5)
    plt.scatter(pca_df.pca0[pca_df.kmeans_label==0], np.zeros((len(pca_df.pca0[pca_df.kmeans_label==0]), 1)), marker='+', color='c', alpha=0.8, s=5)
    plt.scatter(pca_df.pca0[pca_df.kmeans_label==1], np.zeros((len(pca_df.pca0[pca_df.kmeans_label==1]), 1)), marker='o', color='m', alpha=0.8, s=5)
    plt.title('KMeans Clustering'), plt.xlabel('PC1'), plt.ylim(top=1), plt.ylim(bottom=-1)  

    plt.show()

#KPCA
    #Original for KPCA
    plt.figure(figsize=(8, 6), dpi=120)
    plt.suptitle('KPCA for '+filename, fontsize=16)
    plt.subplot(2, 2, 1, aspect='equal')
    plt.scatter(df.x1[df.label==0], df.x2[df.label==0], marker='+', color='c', alpha=0.5, s=5)
    plt.scatter(df.x1[df.label==1], df.x2[df.label==1], marker='o', color='m', alpha=0.5, s=5)
    plt.title('Original Dataset'), plt.xlabel('x'), plt.ylabel('y')

    #Result after KPCA
    kpca_df = executeKPCA(df, dim=2, kfunc=kfunc, gvalue=gvalue)
    plt.subplot(2, 2, 2, aspect='equal')
    plt.scatter(kpca_df.pca0[kpca_df.label==0], kpca_df.pca1[kpca_df.label==0], marker='+', color='c', alpha=0.5, s=5)
    plt.scatter(kpca_df.pca0[kpca_df.label==1], kpca_df.pca1[kpca_df.label==1], marker='o', color='m', alpha=0.5, s=5)
    plt.title('Result after KPCA w/ RBF'), plt.xlabel('PC1'), plt.ylabel('PC2')

    #Reduction to 1D for KPCA
    kpca_df = executeKPCA(df, dim=1, kfunc=kfunc, gvalue=gvalue)
    plt.subplot(2, 2, 3, aspect=0.2)
    plt.scatter(kpca_df.pca0[kpca_df.label==0], np.zeros((500,1)), marker='+', color='c', alpha=0.8, s=10)
    plt.scatter(kpca_df.pca0[kpca_df.label==1], np.zeros((500,1)), marker='o', color='m', alpha=0.8, s=10)
    plt.title('Reduction to 1D'), plt.xlabel('PC1'), plt.ylim(top=1), plt.ylim(bottom=-1), plt.xlim(left=-0.5), plt.xlim(right=0.5)

    #KMeans Clutering for KPCA
    features = kpca_df.loc[:, kpca_df.columns!="label"]
    kmeans = KMeans(n_clusters=2, random_state=0).fit(features)
    kpca_df["kmeans_label"] = kmeans.labels_
    plt.subplot(2, 2, 4, aspect=0.2)
    plt.scatter(kpca_df.pca0[kpca_df.kmeans_label==0], np.zeros((len(kpca_df.pca0[kpca_df.kmeans_label==0]), 1)), marker='+', color='c', alpha=0.8, s=5)
    plt.scatter(kpca_df.pca0[kpca_df.kmeans_label==1], np.zeros((len(kpca_df.pca0[kpca_df.kmeans_label==1]), 1)), marker='o', color='m', alpha=0.8, s=5)
    plt.title('KMeans Clustering'), plt.xlabel('PC1'), plt.ylim(top=1), plt.ylim(bottom=-1), plt.xlim(left=-0.5), plt.xlim(right=0.5)

    plt.show()
    
