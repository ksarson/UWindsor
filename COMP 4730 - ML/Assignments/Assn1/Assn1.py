import sys
import warnings

if not sys.warnoptions:
    warnings.simplefilter("ignore")

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.discriminant_analysis import LinearDiscriminantAnalysis as LDA
from sklearn.discriminant_analysis import QuadraticDiscriminantAnalysis as QDA
from sklearn.naive_bayes import GaussianNB as GNB
from sklearn import svm as SVM
from sklearn.metrics import confusion_matrix
from sklearn.metrics import accuracy_score

dsf = ['circles0.3.csv', 'halfkernel.csv', 'moons1.csv',
                'spiral1.csv', 'twogaussians33.csv', 'twogaussians42.csv']

cfs = ['LDA', 'QDA', 'Bayes', 'SVM']

for ds in dsf:
    df = pd.read_csv('./SampleDatasets/' + ds)
    X = df.iloc[:, [0,1]].values
    y = df.label.values

    for cf in cfs:
        X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=0)

        sc = StandardScaler()
        X_train = sc.fit_transform(X_train)
        X_test = sc.transform(X_test)
        if cf == 'LDA':
            lda = LDA(n_components=1)
            lda.fit(X_train, y_train)
            y_pred = lda.predict(X_test)
        if cf == 'QDA':
            qda = QDA()
            qda.fit(X_train, y_train)
            y_pred = qda.predict(X_test)
        if cf == 'Bayes':
            gnb = GNB()
            gnb.fit(X_train, y_train)
            y_pred = gnb.predict(X_test)
        if cf == 'SVM':
            clf = SVM.SVC(gamma='scale')
            clf.fit(X_train, y_train)
            y_pred = clf.predict(X_test)

        cm = confusion_matrix(y_test, y_pred)
        print(cf + ' for ' + ds)
        print('Confusion Matrix')
        print(cm)
        print('Accuracy ' + str(accuracy_score(y_test, y_pred)))
        print('Positive Predictive Value: ' + "{0:.2f}".format(cm[0][0]/(cm[0][0] + cm[0][1])))
        print('Negative Predictive Value: ' + "{0:.2f}".format(cm[1][1]/(cm[1][1] + cm[1][0])))
        print('Sensitivity: ' + "{0:.2f}".format(cm[0][0]/(cm[0][0] + cm[1][0])))
        print('Specificity: ' + "{0:.2f}".format(cm[1][1]/(cm[1][1] + cm[0][1])))
        print("")

    if ds != 'spiral1.csv':
        ax = df[df.label == 0].plot(x='x1', y='x2',kind='scatter', marker='o', c='blue')
        df[df.label == 1].plot(ax = ax, x='x1', y='x2', kind='scatter',marker='x', c='red')
        plt.show()

    if ds == 'spiral1.csv':
        ax = df[df.label == 0].plot(x='x', y='y',kind='scatter', marker='o', c='blue')
        df[df.label == 1].plot(ax = ax, x='x', y='y', kind='scatter',marker='x', c='red')
        plt.show()
