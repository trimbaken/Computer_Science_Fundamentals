# Data preprocessing
# Importing libraries
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
# Import dataset
print("import data using pandas")
dataset = pd.read_csv('Salary_Data.csv')
X = dataset.iloc[:, :-1].values
Y = dataset.iloc[:,1].values

print("X ", X)
print("Y ", Y)

#Spliting dataset into training set and test set
from sklearn.model_selection import train_test_split
X_train, X_test, Y_train, Y_test = train_test_split(X, Y, test_size = 1/3, random_state = 0)

#Fit simple linear regression to taining set
from sklearn.linear_model import LinearRegression
regressor = LinearRegression()
regressor.fit(X_test, Y_test)

#Predict the Test set result
Y_pred = regressor.predict(X_test)

print("X_test ", X_test)
print("Y_pred ", Y_pred)

# Visualising the Training set results
plt.scatter(X_train, Y_train, color = 'red')
plt.plot(X_train, regressor.predict(X_train), color = 'blue')
plt.title('Salary vs Experience (Training set)')
plt.xlabel('Years of Experience')
plt.ylabel('Salary')
plt.show()

# Visualising the Test set results
plt.scatter(X_test, Y_test, color = 'red')
plt.plot(X_train, regressor.predict(X_train), color = 'blue')
plt.title('Salary vs Experience (Test set)')
plt.xlabel('Years of Experience')
plt.ylabel('Salary')
plt.show()
