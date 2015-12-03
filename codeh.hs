import System.Random

possible_words :: [String]
possible_words = [ " c a t "," c a r "," b e a r "," s h i p "," m o u s e "," b e a t l e "," c o a t "," n e s t "," i c e "," s u g a r "," b a c o n "," f r o w n "," s m i l e "," d e a d "," f e a t h e r "," g o a t "," h e n "," j e l l y "," k o a l a "," l i p s " ]

makeMatrix :: w_ -> [String] -> [String]
makeMatrix = undefined

main :: IO ()
main = do
  g <- getStdGen
  sequence_ $ map putStrLn $ makeMatrix g possible_words
