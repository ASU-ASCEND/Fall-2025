# ASU StratoDevils ASCEND Fall 2025
[Doxygen Docs](https://asu-ascend.github.io/Fall-2025/) | [Website](https://asuascend.weebly.com/) | [YouTube](https://www.youtube.com/@ASUStratoDevilsASCEND)

### Subsystems 
* [Software](#software)
* [Electrical](#electrical)
* [Mechanical](#mechanical)

# Software
Flight software for the ASU Spring 2025 ASCEND Payload. More documentation can be found under [Related Pages](https://asu-ascend.github.io/Fall-2025/pages.html).

## GitHub Subfolders

[DataProcessing](https://github.com/ASU-ASCEND/Spring-2025/tree/main/DataProcessing): Scripts and programs for processing and visualizing flight data.

[GroundStation](https://github.com/ASU-ASCEND/Fall-2025/tree/main/GroundStation): Ground Software GUI built in Python. 

[Testing](https://github.com/ASU-ASCEND/Fall-2025/tree/main/Testing): Test and calibration information for sensor and storage modules.

[Watchdog](https://github.com/ASU-ASCEND/Fall-2025/tree/main/Watchdog): Software for watchdog Attiny85 chip.

[ascendfsw](https://github.com/ASU-ASCEND/Fall-2025/tree/main/ascendfsw): Payload flight software.

[docs_src](https://github.com/ASU-ASCEND/Fall-2025/tree/main/docs_src): Source files for Related Pages documentation. 

[scripts](https://github.com/ASU-ASCEND/Fall-2025/tree/main/scripts): Various organizational and automation scripts. 

A Doxygen auto-generated documentation site for GitHub pages is deployed from the [docs branch](https://github.com/ASU-ASCEND/Fall-2025/tree/docs). 


# Milestones 

## FSW Versions 

### FSWv3 (and earlier)
[Fall 2024 Github](https://github.com/ASU-ASCEND/Fall-2024)

### FSWv4
[Spring 2025 GitHub](https://github.com/ASU-ASCEND/Spring-2025)

## Data Processing Tools

### Visualization 
* [Cesium.js](https://cesium.com/platform/cesiumjs/) 
  * 3D Visualization of the flight 
  * Visualization from Spring 2025: https://www.youtube.com/watch?v=eEC_ttqKnY8
* [D3.js](https://d3js.org/) 
  * 2D Visualization of sensor reading 
* [Jupyter Notebooks](https://jupyter.org/)
  * Data cleaning and [Skew-T Log-P Diagram](https://en.wikipedia.org/wiki/Skew-T_log-P_diagram) using [MetPy](https://unidata.github.io/MetPy/latest/)

### Groundstation GUI
[/Groundstation](https://github.com/ASU-ASCEND/Fall-2025/tree/main/Groundstation)
#### Backend
* Serial Connection 
* Serial Sorter 
* Packet Parser 
* Serial Sender
* File log dumps
* Server Interface/Process

#### Frontend 
* GUI for displaying 
  * Decoded Packet 
  * Sorted Core Debug Prints 
* Flash Data Recovery Interface 

# Electrical


# Mechanical 
### CAD Models 