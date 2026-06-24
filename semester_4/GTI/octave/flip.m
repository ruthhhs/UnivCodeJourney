function y = flip(x, f)
  [m, n, d] = size(x);
  y = zeros(m, n, d, class(x));

  if strcmp(f, "x")
    for i = 1:m
      for j = 1:n
        y(i, j, :) = x(i, n - j + 1, :);
      endfor
    endfor

  elseif strcmp(f, "y")
    for i = 1:m
      for j = 1:n
        y(i, j, :) = x(m - i + 1, j, :);
      endfor
    endfor
  endif
endfunction
