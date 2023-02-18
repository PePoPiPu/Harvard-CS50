SELECT AVG(ratings.rating) FROM ratings JOIN movies ON ratings.movie_id = movies.id WHERE movies.year = '2012';


SELECT AVG(rating) FROM ratings WHERE movie_id = (SELECT id FROM movies WHERE year = '2012');