
SELECT title FROM movies WHERE id = (SELECT * FROM ratings WHERE rating = '10');