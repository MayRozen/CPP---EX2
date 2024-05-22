בס"ד

ID: 212051007
Mail: mayrozen45@gmail.com

מטלה 2 - תכנות מערכות 2:
במטלה זו התמקדנו ביצירת אופרטורים על גרפים. כעת אפרט על כל אופרטור בקצרה, על המימוש שלו וכיצד בחרתי לגשת למשתנים או להחזירם מהאופרטור.
נשים לב תחילה שבקובץ hpp כלל האופרטורים מוצהרים עם "friend". זאת על מנת שנוכל לגשת לשדות של הגרף באופן ישיר דרך אותה מחלקה בה מימשנו את האופרטורים - Graph.cpp.
בנוסף, נשים לב לערכי ההחזרה של כל פונקציה. ישנן פונקציות שבהן עבדנו ישירות על ה - reference של הגרף ולכן אין צורך להחזיר אותו. השינוי שבו (עקב האופרטור שהפעלנו עליו) יהיה שמור בגרף המקור ומשם נוכל לגשת לגרף המעודכן.
כהמשך לכך, במקרים אלו, קלט הפונקציה הוא ה - reference של הגרף ולא העתק שלו.

כעת נפרט על כל פונקציה:
בפונקציה זו ביצענו חיבור בין שני גרפים. כלומר, בין כל שתי צלעות הגרף בהתאם לקודקודיו. כל זאת בהתאם למטריצת השכנויות ממנה הגרף מורכב.

        friend Graph operator+(const Graph& g1, const Graph& g2); // plus operator

בפונקציה זו התבססנו על אופרטור החיבור רק שהאופרטור כעת כתוב בצורה מקוצרת על ידי הסימון +=.

        friend void operator+=(Graph& g1, Graph& g2); // addition operator

בפונקציה זו ביצענו פלוס אונרי. כלומר, הפכנו את כל צלעות הגרף לחיוביות. זאת על ידי מעבר על מטריצת השכנויות ממנה הגרף מורכב, זיהוי צלע שלילית והפיכת משקלה לחיובי.

        friend void operator+(Graph& g); // Unary plus operator
בדומה לחיבור בין שני גרפים, מימשנו גם את פעולת החיסור הפועלת באופן זהה אך מבצעת חיסור בין ערכי צלעות הגרפים ולא חיבור.

        friend Graph operator-(const Graph& g1, const Graph& g2); // matrix subtraction operator

באופרטור זה ביצענו חיסור בין גרפים אך על ידי סימון מקוצר -=.

        friend void operator-=(Graph& g1, Graph& g2); // subtraction operator

באופרטור זה ביצענו מינוס אונרי. כלומר, עברנו על מטריצת השכנויות וכל צלע שזוהתה כחיובית הפכנו לשלילית.

        friend void operator-(Graph& g); // Unary minus operator

        friend bool operator>(Graph g1, Graph g2);
        friend bool operator>=(Graph g1, Graph g2);
        friend bool operator<(Graph g1, Graph g2);
        friend bool operator<=(Graph g1, Graph g2);
        friend bool operator==(const Graph& g1, const Graph& g2);
        friend bool operator!=(const Graph& g1, const Graph& g2);

        friend Graph& operator++(Graph &g); //++n
        friend const Graph operator++(Graph &g, int); // n++
        friend Graph& operator--(Graph &g); //--n
        friend const Graph operator--(Graph &g, int); // n--

        friend void operator*(Graph& g, int c); // Multiplication by a scalar
        friend void operator*=(Graph &g, int c); // Multiply the graph by int
        friend void operator/=(Graph &g, int c); // Dividing the graph by int

        friend Graph operator*(const Graph& g1, const Graph& g2); // Graph Multiplication

        friend std::ostream& operator<<(std::ostream &os, const Graph& g); // Print Graph
