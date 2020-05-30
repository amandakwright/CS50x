SELECT DISTINCT people.name
FROM movies
JOIN stars on movies.id = stars.movie_id
JOIN people on stars.person_id = people.id
WHERE movies.id IN
	(SELECT movies.id
	FROM movies
	JOIN stars on movies.id = stars.movie_id
	JOIN people on stars.person_id = people.id
	WHERE people.name = "Kevin Bacon" AND people.birth = 1958)
	AND people.name != "Kevin Bacon";
