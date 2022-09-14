SELECT AVG(rating) FROM ratings
JOIN movies ON ratings.movie_id = movie.id
WHERE YEAR = 2012;
