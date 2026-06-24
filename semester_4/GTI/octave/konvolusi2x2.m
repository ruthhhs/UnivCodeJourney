function y = konvolusi2x2(x, k)
  [m, n] = size(x);
  y = zeros(m, n);

  for i = 1 : m-1,
    for j = 1 : n-1,
      y(i,j) = x(i,j) * k(1,1) + ...
               x(i,j+1) * k(1,2) + ...
               x(i+1,j) * k(2,1) + ...
               x(i+1,j+1) * k(2,2);
    endfor
  endfor
 endfunction
