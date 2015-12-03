import Data.List
import Data.List.Split
import System.Random

possible_words :: [String]
possible_words = [ "cat", "car", "bear", "ship", "mouse", "beatle", "coat", "nest", "ice", "sugar", "bacon", "frown", "smile", "dead", "feather", "goat", "hen", "jelly", "koala", "lips" ]

select :: (Eq a) => [Int] -> [a] -> [a]
select [] _ = []
select (x:xs) choices =
  let choice = choices!!(max 0 (min x ((length choices) - 1)))
  in choice:((select xs (delete choice choices)))

fillMatrix :: [String] -> [String] -> [String]
fillMatrix [] _ = []
fillMatrix matrix [] = matrix
fillMatrix (line:rest) (word:words) =
  (word ++ drop (length word) line):fillMatrix rest words

makeMatrix :: StdGen -> Int -> Int -> [String] -> [String]
makeMatrix g x y possible_words =
  let (wordrs, letterrs) = splitAt 4 $ take (4 + x * y) $ randoms g
      words = select wordrs possible_words
      letters = map (['a'..]!!) $ map ((flip mod) 26) $ map (abs) letterrs
      matrix_init = chunksOf x letters
      filled_matrix = fillMatrix matrix_init words
  in intersperse [] $ map (intersperse '\t') $ (' ':take x ['A'..]):(zipWith (:) ['0'..] filled_matrix)

main :: IO ()
main = do
  g <- getStdGen
  sequence_ $ map putStrLn $ makeMatrix g 10 10 possible_words
