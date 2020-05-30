SELECT AVG (ratings.rating)
FROM movies
join ratings on ratings.movie_id = movies.id
WHERE movies.year = 2012;
