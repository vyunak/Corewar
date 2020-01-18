.name "Rail Factory"
	.comment "RODA ROLLA-DA!"

	st r1, r4
	ld %1879273475, r3
	ld %0, r2

start:
	live %42
	fork %:port
	fork %:first
	zjmp %:start

port:
	fork %:second

third:
	st r4, 6
	live %42
	fork %-5
	zjmp %:3start

second:
	st r4, 6
	live %42
	fork %-5
	zjmp %:2start

first:
	st r4, 6
	live %42
	fork %-5
	zjmp %:1start

3start:
	live %42
	zjmp %23

2start:
	live %42
	zjmp %13

1start:
	live %42
	zjmp %3

	st r3, 28675
