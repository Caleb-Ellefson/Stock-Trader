SELECT movies.id, movies.title, stars.person_id FROM movies
JOIN stars ON stars.movie_id = movies.id
WHERE title = 'Toy Story';