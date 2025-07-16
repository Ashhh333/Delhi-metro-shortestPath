import csv

# Raw station list as a multi-line string
stations_raw = """
Samaypur Badli
Rohini Sector 18/19
Haiderpur Badli Mor
Jahangirpuri
Adarsh Nagar
Azadpur
Model Town
GTB Nagar
Vishwa Vidyalaya
Vidhan Sabha
Civil Lines
Kashmere Gate
Chandni Chowk
Chawri Bazar
New Delhi
Rajiv Chowk
Patel Chowk
Central Secretariat
Udyog Bhawan
Lok Kalyan Marg
Jor Bagh
Dilli Haat-INA
AIIMS
Green Park
Hauz Khas
Malviya Nagar
Saket
Qutub Minar
Chhattarpur
Sultanpur
Ghitorni
Arjan Garh
Guru Dronacharya
Sikandarpur
MG Road
IFFCO Chowk
Millennium City Centre
Janakpuri West
Dabri Mor
Dashrath Puri
Palam
Sadar Bazaar Cantonment
Terminal 1 IGI Airport
Shankar Vihar
Vasant Vihar
Munirka
R.K Puram
IIT Delhi
Panchsheel Park
Chirag Delhi
Greater Kailash
Nehru Enclave
Kalkaji Mandir
Okhla NSIC
Sukhdev Vihar
Jamia Millia Islamia
Okhla Vihar
Jasola Vihar Shaheen Bagh
Kalindi Kunj
Okhla Bird Sanctuary
Botanical Garden
Majlis Park
Shalimar Bagh
Netaji Subhash Place
Shakurpur
Punjabi Bagh West
ESI Basaidarapur
Rajouri Garden
Mayapuri
Naraina Vihar
Delhi Cantt
Durgabai Deshmukh South Campus
Sir Vishweshwaraiah Moti Bagh
Bhikaji Cama Place
Sarojini Nagar
South Extension
Lajpat Nagar
Vinobapuri
Ashram
Sarai Kale khan Nizamuddin
Mayur Vihar Phase 1
Mayur Vihar Pocket 1
Trilokpuri-Sanjay Lake
East Vinod Nagar-Mayur Vihar-II
Mandawali-West Vinod Nagar
IP Extension
Anand Vihar
Karkarduma
Karkarduma Court
Krishna Nagar
East Azad Nagar
Welcome
Jaffrabad
Maujpur-Babarpur
Gokulpuri
Johri Enclave
Shiv Vihar
Dwarka Sector 21
Dwarka Sector 8
Dwarka Sector 9
Dwarka Sector 10
Dwarka Sector 11
Dwarka Sector 12
Dwarka Sector 13
Dwarka Sector 14
Dwarka
Dwarka Mor
Nawada
Uttam Nagar West
Uttam Nagar East
Janakpuri East
Tilak Nagar
Subhash Nagar
Tagore Garden
Ramesh Nagar
Moti Nagar
Kirti Nagar
Shadipur
Patel Nagar
Rajendra Place
Karol Bagh
Jhandewalan
R. K. Ashram Marg
Barakhamba Road
Mandi House
Supreme Court
Indraprastha
Yamuna Bank
Akshardham
Mayur Vihar Extension
New Ashok Nagar
Noida Sector 15
Noida Sector 16
Noida Sector 18
Golf Course
Noida City Centre
Noida Sector 34
Noida Sector 52
Noida Sector 61
Noida Sector 59
Noida Sector 62
Noida Electronic City
Laxmi Nagar
Nirman Vihar
Preet Vihar
Kaushambi
Vaishali
Rithala
Rohini West
Rohini East
Pitampura
Kohat Enclave
Keshav Puram
Kanhaiya Nagar
Inderlok
Shastri Nagar
Pratap Nagar
Pul Bangash
Tis Hazari
Shastri Park
Seelampur
Shahdara
Mansarovar Park
Jhilmil
Dilshad Garden
Shaheed Nagar
Raj Bagh
Major Mohit Sharma Rajendra Nagar
Shyam Park
Mohan Nagar
Arthala
Hindon River
Shaheed Sthal
Ashok Park Main
Punjabi Bagh
Shivaji Park
Madipur
Paschim Vihar East
Paschim Vihar West
Peeragarhi
Udyog Nagar
Surajmal Stadium
Nangloi
Nangloi Railway Station
Rajdhani Park
Mundka
Mundka Industrial Area
Ghevra Metro Station
Tikri Kalan
Tikri Border
Pandit Shree Ram Sharma
Bahadurgarh City
Brigadier Hoshiar Singh
Satguru Ram Singh Marg
"""

# Convert raw string to a list of stations
stations = [station.strip() for station in stations_raw.strip().split('\n')]

# Split into columns based on index
yellow = stations[0:37]
magenta = stations[37:61]
pink = stations[61:97]
blue1 = stations[97:147]
red = stations[147:173]
green = stations[173:194]

# # Merge blue lines
# blue = blue1 + blue2

# Pad lists to the same length
max_len = max(len(yellow), len(magenta), len(pink), len(blue1), len(red), len(green))
def pad(lst): return lst + [''] * (max_len - len(lst))

yellow = pad(yellow)
magenta = pad(magenta)
pink = pad(pink)
blue = pad(blue1)
red = pad(red)
green =pad(green)

# Write to CSV
with open('metro_lines2.csv', 'w', newline='', encoding='utf-8') as f:
    writer = csv.writer(f)
    writer.writerow(['Yellow line', 'Magenta line', 'Pink line', 'Blue line', 'Red line', 'Green line'])
    for row in zip(yellow, magenta, pink, blue, red, green):
        writer.writerow(row)

print("CSV file 'metro_lines.csv' has been created.")
