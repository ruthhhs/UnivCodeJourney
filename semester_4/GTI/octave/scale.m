function y = scale(x, s)
  [m, n, d] = size(x);

  new_m = round(m * s);
  new_n = round(n * s);

  y = zeros(new_m, new_n, d, class(x));

  for i = 1:new_m
    for j = 1:new_n
      old_i = round(i / s);
      old_j = round(j / s);

      if (old_i >= 1 && old_i <= m && old_j >= 1 && old_j <= n)
        y(i, j, :) = x(old_i, old_j, :);
      endif
    endfor
  endfor
endfunction
