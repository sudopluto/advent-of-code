
# select file

  def recur([left | [right | tail]], acc) when right > left, do: recur([right | tail], acc + 1)

input = "input.txt"

#load file into list
case File.read(input) do 
    {:ok, content} ->
    # contents : list[string]
    # content -> map(to_integer) -> reduce( ([prev val, cnt], next val) -> [prev val, cnt]) -> [1] cnt

    cnt = 0
    prev = -1
    content = String.split(content)

    for val <- content do 
        prev = if prev == -1 do val else prev end
        cnt = if prev < val do cnt + 1 else cnt end
    end |> IO.puts

    IO.puts cnt

    {:error, :enoent} -> 
        IO.puts input <> " file doesn't exist"
end
