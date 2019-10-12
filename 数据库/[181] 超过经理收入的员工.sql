SELECT a.name as 'Employee'
FROM Employee as a
JOIN Employee as b
ON a.ManagerId = b.Id AND a.Salary > b.Salary