function y = roberts2x2(x)
  x = im2double(x);

  % kernel roberts
  rx = [1 0;
        0 -1];
  ry = [0 1;
        -1 0];

  % konvolusi
  gx = konvolusi2x2(x, rx);
  gy = konvolusi2x2(x, ry);

  y = sqrt(gx.^2 + gy.^2);
  y = y / max(y(:));

 endfunction
