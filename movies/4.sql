SELECT movie_id FROM ratings WHERE rating = '10';
SELECT title FROM movies WHERE movie_id FROM ratings = '10'
Select name FROM songs WHERE artist_id = (SELECT id FROM artists WHERE name = 'Post Malone');
SELECT title FROM movies WHERE * = (SELECT * FROM ratings WHERE rating = '10');