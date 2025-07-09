from sklearn.datasets import load_breast_cancer
from sklearn.model_selection import train_test_split
from sklearn.model_selection import RandomizedSearchCV
from sklearn.svm import SVC
from sklearn.metrics import classification_report, accuracy_score
from sklearn.preprocessing import StandardScaler
import joblib

data = load_breast_cancer()
X = data.data
y = data.target
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2)
param_grid = {
    'kernel': ['linear', 'rbf', 'poly', 'sigmoid'],
    'C': [0.1, 1, 10, 100],
    'gamma': ['scale', 'auto']
}

X_temp, _, y_temp, _ = train_test_split(X_train, y_train, test_size=0.5)

print("Starting grid search...")
grid = RandomizedSearchCV(SVC(), param_grid, n_jobs=-1, verbose=2, n_iter=20)
grid.fit(X_temp, y_temp)
model = grid.best_estimator_
print("Best parameters found: ", grid.best_params_)
model.fit(X_train, y_train)
y_pred = model.predict(X_test)
print(accuracy_score(y_test, y_pred))
print(classification_report(y_test, y_pred))
joblib.dump(model, 'digits_model.pkl')
