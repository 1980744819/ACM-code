<?php
$b = "windows";
function print_b()
{
    $b = "linux";
}

print_b();
echo "B值为：" . $b . "</br>";