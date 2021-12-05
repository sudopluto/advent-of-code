def main()
  count = 0
  pos_x = 0
  pos_y = 0
  rep = $stdin.read.split("\n")

  while pos_y < rep.size
  
    #increase count if a tree
    count += 1 if rep[pos_y][pos_x] == '#'
   
    pos_x = (pos_x + 3) % rep[0].size

    pos_y += 1
  end
  puts count
end

main
