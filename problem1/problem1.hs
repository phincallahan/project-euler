f x y = sum [0,x..y-1]
main = print $ f 3 1000 + f 5 1000 - f 15 1000