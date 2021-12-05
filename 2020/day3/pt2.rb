def main()

  rep = $stdin.read.split("\n")

  delt_x = [1, 3, 5, 7, 1]
  delt_y = [1, 1, 1, 1, 2]

  idx = 0
  tot = 1

  while idx < delt_x.size
    count = 0
    pos_x = 0
    pos_y = 0
    while pos_y < rep.size
    
      #increase count if a tree
      count += 1 if rep[pos_y][pos_x] == '#'
     
      pos_x = (pos_x + delt_x[idx]) % rep[0].size

      pos_y += delt_y[idx]
    end

    tot *= count
    idx += 1
  end
  puts tot
end

main
