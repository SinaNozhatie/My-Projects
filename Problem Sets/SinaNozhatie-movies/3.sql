--all movies from 2018 until now with alphebatical order

SELECt title FROM movies
WHERE year >= 2018
ORDER BY title ASC;
