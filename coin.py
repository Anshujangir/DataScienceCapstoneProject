def coin_change_greedy(n):
  coins = [20, 10, 5, 1]
  i = 0

  while(n>0):
    if(coins[i] > n):
      i = i+1
    else:
      print(coins[i])
      n = n-coins[i];
  print("\n\n\n\n")

if __name__ == '__main__':
  for i in range(1, 21):
    coin_change_greedy(i)
