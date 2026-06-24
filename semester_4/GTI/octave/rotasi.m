function y = rotasi(x, theta)
  [m, n, d] = size(x);

  y = zeros(m, n, d, class(x));

  cx = (n + 1) / 2;
  cy = (m + 1) / 2;

  t = theta * pi / 180;

  for i = 1:m
    for j = 1:n
      x0 = j - cx;
      y0 = i - cy;

      old_x =  x0 * cos(t) + y0 * sin(t);
      old_y = -x0 * sin(t) + y0 * cos(t);
      old_j = round(old_x + cx);
      old_i = round(old_y + cy);

      if (old_i >= 1 && old_i <= m && old_j >= 1 && old_j <= n)
        y(i, j, :) = x(old_i, old_j, :);
      endif
    endfor
  endfor
endfunction
