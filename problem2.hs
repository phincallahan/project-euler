fib :: [Integer]
fib = 0:1:zipWith (+) fib (tail fib)

f :: Integer -> Integer
f n = sum (takeWhile (<n) (filter even fib))

main = print $ f 4000000