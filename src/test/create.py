with open("Contacts10000.txt", "w", encoding="utf-8") as f:
    for i in range(1101, 11101):
        name = f"Le Huu Minh Phu{i}"
        phone = f"0987{str(i).zfill(6)}"
        email = f"minhphu{i}@example.com"
        address = "Hanoi"
        f.write(f"{name},{phone},{email},{address}\n")