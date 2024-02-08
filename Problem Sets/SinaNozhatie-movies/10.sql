-- all directors who received at least a 9.0 on ratings

SELECT DISTINCT name FROM people
JOIN directors ON directors.person_id = people.id
JOIN movies ON movies.id = directors.movie_id
JOIN ratings ON ratings.movie_id = movies.id
WHERE rating >= 9.0;