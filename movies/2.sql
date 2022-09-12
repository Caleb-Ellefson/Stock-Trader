
SELECT birth FROM people WHERE name = (SELECT * FROM people WHERE name = 'Emma Stone');