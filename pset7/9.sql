SELECT
	unique_names.name
FROM
	(SELECT DISTINCT people.id,
	people.name
	FROM movies
	JOIN stars on movies.id = stars.movie_id
	JOIN people on stars.person_id = people.id
	WHERE movies.year = 2004
	ORDER BY people.birth) unique_names
