SELECT person_id FROM directors
JOIN directors on person.id = directors.person_id
JOIN ratings on directors.movie_id = ratings.movie_id
WHERE rating >= 9.0;