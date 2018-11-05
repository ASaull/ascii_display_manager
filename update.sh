exec g++ -o adm adm.cpp -lncurses
exec sudo systemctl daemon-reload
exec sudo systemctl restart getty@tty2.service
