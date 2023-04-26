
# Project Overview


Container farms are becoming increasingly popular within the controlled environment agriculture industry. These farms are usually vertical farming systems installed inside a shipping container. The main objective is to make sure the local temperature is below 16 degrees Celcius with 80% of humidity so the plant can grow inside a controlled hygiene container. To do so, the container is equipped with AC, Fans, and an automatic watering and monitoring system.


![Figure1](https://user-images.githubusercontent.com/39290210/234052121-e2424afc-c1fd-422f-9c5c-0e3cfd807a08.jpg)

During the manufacturing process, we had a lot of discussions with good friends from agricultural technology and PIAT (Center for Agro-Technology Innovation) UGM to produce a suitable and sustainable product.

Among our discussion topics was the system's design to meet the plant and electronic requirements. The discussion process resulted in the flow chart below

![Figure1](https://user-images.githubusercontent.com/39290210/234051990-3875954b-4d23-4a51-b465-15a85c1923a6.jpg)



# Directory


To short things out, this is the directories of this project.

- [Article](https://www.linkedin.com/posts/naufalaryaputra_contagrow-an-automated-container-hydroponic-activity-6986608747372494849-8hf9?utm_source=share&utm_medium=member_desktop)
 - [Electrical Design](https://github.com/naufalra/Contagrows/tree/main/1.%20Electrical)
 - [Mechanical Design](https://github.com/naufalra/Contagrows/tree/main/3.%20Mechanical)
 - [Arduino Program](https://github.com/naufalra/Contagrows/tree/main/2.%20Firmware)


# Intelligent property rights

**Alat Otomasi dan Monitoring Budidaya Hidroponik**

```bash
  https://pdki-indonesia.dgip.go.id/detail/A00202203526?type=di&keyword=A00202203526 
```

**Media Tanam Pertanian Vertikal Hidroponik pada Kontainer**

```bash
 https://pdki-indonesia.dgip.go.id/detail/A00202203525?type=di&keyword=A00202203525
```

# Final Result
![Electrical](https://user-images.githubusercontent.com/39290210/234175010-8649c43a-4a43-4684-89ae-32dccd52d0e7.jpg)

## Electronics System
The control system itself is using Arduino Mega2560 as the main processor. The Arduino is connected to several built in sensors like DHT11, BME280, the boards is also provide more ports for additional sensor.
![Electrical](https://user-images.githubusercontent.com/39290210/234173587-72e163b2-47f3-4e63-96a3-68975e849d3c.png)

## Wiring
We divided the panel into two parts to simplify the troubleshooting process and panel tidiness. 

The right panel (the one without LCD) functions as an electrical panel directly connected to the source. This panel also acts as the main switch.

The second panel only serves as the system control and automation of the tool. All control, monitoring, and automation are done through this panel. It is on this panel that the Arduino and sensors are placed.
![Electrical](https://user-images.githubusercontent.com/39290210/234173796-17f0c13c-b5a4-4f1c-b2ff-48231551bda8.jpg)

![Electrical](https://user-images.githubusercontent.com/39290210/234173799-e4c3c2bf-4f4c-46a2-8453-63678fbf98bd.jpg)

We realize that many things can be improved in our electronic and wiring systems, but we have not had the chance to do so due to limited time. The safety process has also not been maximized because all energy has been diverted to the automation system.



## Mechanical Design
This system utilizes a 20-foot container to work. The container was chosen because it is easier to place in urban areas. Still, on the inside, we added several other components to support the needs, including plant shelves, setting panels, and screen protectors on boards to protect from water and dust.

### Shelf
The shelf is designed to accommodate approximately 1000 plant seeds placed in polybags. The rack design considers the plant seeds' maximum capacity and the container's space.

![Shelfs](https://user-images.githubusercontent.com/39290210/234172968-abfa1ffb-fad4-43f3-bc5f-310730e62c81.png)

### Panel Box
The panel box is used as the setting center of the tool before the automation process takes place. In addition, on the panel, there is also a sensor reading value viewer to be monitored.

![PanelBox](https://user-images.githubusercontent.com/39290210/234172967-dba71c24-0951-441a-8752-1fdd70b0a329.png)

### LCD protectors
We also ad LCD protector as an additional protection for LCD from dust and water drops.
![PanelBox](https://user-images.githubusercontent.com/39290210/234172961-44cd830b-c37a-46a3-8a55-6677136c2436.png)

## Overall System
This is the final result of recent design
![PanelBox](https://user-images.githubusercontent.com/39290210/234467175-9d5296a6-133c-400f-b2c6-a7ed8bbc9f86.jpg)

![PanelBox](https://user-images.githubusercontent.com/39290210/234467186-87b9bc23-5988-4874-8410-a479a6a61f9f.png)



