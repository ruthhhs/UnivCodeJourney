let teks = "Narahubung kami dapat dihubungi melalui 0853-6689-8234 atau 0852-3457-9364";
let pola = /08[0-9]{2}-[0-9]{4}-[0-9]{4}/g;

let hasil = teks.match(pola);

if (hasil){
    console.log("Nomor ditemukan pada:");
    console.log(hasil);
} else{
    console.log("Nomor tidak ditemukan.");
}
