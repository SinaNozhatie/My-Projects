-- all movies in 2010 and descending rating

SELECT title, rating FROM movies
JOIN ratings ON movies.id = ratings.movie_id
WHERE year = 2010
ORDER BY rating DESC, title ASC;