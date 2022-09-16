SELECT name FROM people
JOIN stars ON stars.person_id = person_id
JOIN movies on stars.movie_id = movie.id
WHERE movies.year = 2004
ORDER BY people.birth
