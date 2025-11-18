<?php
$teks = "Narahubung kami dapat dihubungi melalui 0853-6689-8234 atau 0852-3457-9364";
$pola = "/08[0-9]{2}-[0-9]{4}-[0-9]{4}/";

if (preg_match_all($pola, $teks, $hasil)) {
    echo "Nomor ditemukan pada:\n";
    foreach ($hasil[0] as $nomor) {
        echo $nomor."\n";
    }
} else{
    echo "Nomor tidak ditemukan.\n";
}
?>
