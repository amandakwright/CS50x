SELECT DISTINCT people.name
FROM ratings
JOIN directors on ratings.movie_id = directors.movie_id
JOIN people on directors.person_id = people.id
WHERE ratings.rating >= 9.0;