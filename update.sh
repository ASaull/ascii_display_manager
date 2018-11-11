sudo -u $USER g++ -o adm adm.cpp -lncurses
systemctl daemon-reload
systemctl restart getty@tty2.service
