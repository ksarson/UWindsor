# Load libraries
import pandas as pd
import numpy as np
import seaborn as sns
import matplotlib.pyplot as plt
from sklearn.metrics import confusion_matrix 
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.decomposition import KernelPCA
from sklearn.svm import SVC
from sklearn.ensemble import RandomForestRegressor as RFR

data = pd.read_csv("Breastcancer.csv")

data.isnull().sum()
data.isna().sum()

feature_cols = data.iloc[:, :-1].columns
X = data[feature_cols]
y = data.Class

methods = ['SVM-Linear', 'SVM-RBF', 'RFR', 'VS+SVM-Linear', 'VS+RFR', 'KPCA+SVM-Linear', 'KPCA+RFR']
testvalues = [1, 2, 4, 6, 8, 10, 25, 50, 100]
dataset = {'Test-Values': testvalues}

for method in methods:
    dataset[method] = []
    for value in testvalues:
        # dividing X, y into train and test data 
        X_train, X_test, y_train, y_test = train_test_split(X, y, random_state = 0)

        sc = StandardScaler()
        X_train = sc.fit_transform(X_train)
        X_test = sc.transform(X_test)

        if method=='SVM-Linear':
            svm_model_linear = SVC(kernel = 'linear', C=value).fit(X_train, y_train) 
            svm_predictions = svm_model_linear.predict(X_test) 
                      
            accuracy = svm_model_linear.score(X_test, y_test)

            if accuracy <= 0.0:
                accuracy = '-'

            print("SVM w/ Linear Kernel Accuracy at "+str(value)+" components: "+ str(accuracy))

        if method=='SVM-RBF':
            svm_model_linear = SVC(kernel = 'rbf', C=value).fit(X_train, y_train) 
            svm_predictions = svm_model_linear.predict(X_test) 
                      
            accuracy = svm_model_linear.score(X_test, y_test)

            if accuracy <= 0.0:
                accuracy = '-'

            print("SVM w/ RBF Kernel Accuracy at "+str(value)+" components: "+ str(accuracy))

        if method=='RFR':
            newY = y
            newY = np.where(y=='Basal', 0, newY)
            newY = np.where(y=='Her2', 1, newY)
            newY = np.where(y=='LumA', 2, newY)
            newY = np.where(y=='LumB', 3, newY)
            newY = np.where(y=='Normal', 4, newY)

            X_train, X_test, y_train, y_test = train_test_split(X, newY, random_state = 0)

            sc = StandardScaler()
            X_train = sc.fit_transform(X_train)
            X_test = sc.transform(X_test)

            clf = RFR(max_depth=value, random_state=0, n_estimators=100)
            clf_model = clf.fit(X_train, y_train)
            clf_predictions = clf_model.predict(X_test)

            accuracy = clf_model.score(X_test, y_test)

            if accuracy <= 0.0:
                accuracy = '-'

            print("RFR Accuracy at "+str(value)+" components: "+ str(accuracy))

        if method=='VS+SVM-Linear':
            var = X.var()
            var.sort_values(ascending=False)
            col_subset = [ ]
            
            for i in range(value):
                   col_subset.append(var.index[i])

            X_train, X_test, y_train, y_test = train_test_split(X[col_subset], y, random_state = 0)

            sc = StandardScaler()
            X_train = sc.fit_transform(X_train)
            X_test = sc.transform(X_test)
                
            svm_model_linear = SVC(kernel = 'linear', C=value).fit(X_train, y_train) 
            svm_predictions = svm_model_linear.predict(X_test) 
                          
            accuracy = svm_model_linear.score(X_test, y_test)

            if accuracy <= 0.0:
                accuracy = '-'
                
            print("VS+SVM w/ Linear Kernel Accuracy at "+str(value)+" components: "+ str(accuracy))

        if method=='VS+RFR':
            var = X.var()
            var.sort_values(ascending=False)
            col_subset = [ ]
            
            for i in range(value):
                   col_subset.append(var.index[i])

            newY = y
            newY = np.where(y=='Basal', 0, newY)
            newY = np.where(y=='Her2', 1, newY)
            newY = np.where(y=='LumA', 2, newY)
            newY = np.where(y=='LumB', 3, newY)
            newY = np.where(y=='Normal', 4, newY)

            X_train, X_test, y_train, y_test = train_test_split(X[col_subset], newY, random_state = 0)

            sc = StandardScaler()
            X_train = sc.fit_transform(X_train)
            X_test = sc.transform(X_test)

            clf = RFR(max_depth=6, random_state=0, n_estimators=100)
            clf_model = clf.fit(X_train, y_train)
            clf_predictions = clf_model.predict(X_test)

            accuracy = clf_model.score(X_test, y_test)

            if accuracy <= 0.0:
                accuracy = '-'

            print("VS + RFR Accuracy at "+str(value)+" components: "+ str(accuracy))

        if method=='KPCA+SVM-Linear':
            pca = KernelPCA(n_components=value)
            X_train = pca.fit_transform(X_train)
            X_test = pca.transform(X_test)

            svm_model_linear = SVC(kernel = 'linear', C = value).fit(X_train, y_train) 
            svm_predictions = svm_model_linear.predict(X_test) 
                          
            accuracy = svm_model_linear.score(X_test, y_test)

            if accuracy <= 0.0:
                accuracy = '-'

            print("KPCA+SVM w/ Linear Kernel Accuracy at "+str(value)+" components: "+ str(accuracy))
        if method=='KPCA+RFR':
            newY = y
            newY = np.where(y=='Basal', 0, newY)
            newY = np.where(y=='Her2', 1, newY)
            newY = np.where(y=='LumA', 2, newY)
            newY = np.where(y=='LumB', 3, newY)
            newY = np.where(y=='Normal', 4, newY)

            X_train, X_test, y_train, y_test = train_test_split(X[col_subset], newY, random_state = 0)

            sc = StandardScaler()
            X_train = sc.fit_transform(X_train)
            X_test = sc.transform(X_test)
            
            pca = KernelPCA(n_components=value)
            X_train = pca.fit_transform(X_train)
            X_test = pca.transform(X_test)

            clf = RFR(max_depth=6, random_state=0, n_estimators=100)
            clf_model = clf.fit(X_train, y_train)
            clf_predictions = clf_model.predict(X_test)

            accuracy = clf_model.score(X_test, y_test)

            if accuracy <= 0.0:
                accuracy = '-'

            print("KPCA+RFR Accuracy at "+str(value)+" components: "+ str(accuracy))

        dataset[method].append(accuracy)

dataframe = pd.DataFrame(dataset)
print(dataframe)
dataframe.to_csv('accuracy_table.csv')


