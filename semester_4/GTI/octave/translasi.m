function y = translasi(x, tx, ty)
  [m, n, d] = size(x);
  y = zeros(m, n, d, class(x));

  for i = 1:m
    for j = 1:n
      new_i = i + ty;
      new_j = j + tx;

      if (new_i >= 1 && new_i <= m && new_j >= 1 && new_j <= n)
        y(new_i, new_j, :) = x(i, j, :);
      endif
    endfor
  endfor
endfunction
