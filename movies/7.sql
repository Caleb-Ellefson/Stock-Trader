SELECT ASC(rating) FROM ratings
JOIN movies ON rating.movie_id = movies.id
SELECT title, year FROM movies
WHERE year = 2010
