SELECT AVG(rating) FROM ratings
JOIN ratings ON movies.id = ratings.movie_id
WHERE YEAR = '2012';