בס"ד

ID: 212051007
Mail: mayrozen45@gmail.com

מטלה 2 - תכנות מערכות 2:
במטלה זו התמקדנו ביצירת אופרטורים על גרפים. כעת אפרט על כל אופרטור בקצרה, על המימוש שלו וכיצד בחרתי לגשת למשתנים או להחזירם מהאופרטור.
נשים לב תחילה שבקובץ hpp כלל האופרטורים מוצהרים עם "friend". זאת על מנת שנוכל לגשת לשדות של הגרף באופן ישיר דרך אותה מחלקה בה מימשנו את האופרטורים - Graph.cpp.
בנוסף, נשים לב לערכי ההחזרה של כל פונקציה. ישנן פונקציות שבהן עבדנו ישירות על ה - reference של הגרף ולכן אין צורך להחזיר אותו. השינוי שבו (עקב האופרטור שהפעלנו עליו) יהיה שמור בגרף המקור ומשם נוכל לגשת לגרף המעודכן.
כהמשך לכך, במקרים אלו, קלט הפונקציה הוא ה - reference של הגרף ולא העתק שלו.

כעת נפרט על כל פונקציה:

        friend Graph operator+(const Graph& g1, const Graph& g2); // plus operator
בפונקציה זו ביצענו חיבור בין שני גרפים. כלומר, בין כל שתי צלעות הגרף בהתאם לקודקודיו. כל זאת בהתאם למטריצת השכנויות ממנה הגרף מורכב.

        friend void operator+=(Graph& g1, Graph& g2); // addition operator

        friend void operator+(Graph& g); // Unary plus operator
        friend Graph operator-(const Graph& g1, const Graph& g2); // matrix subtraction operator
        friend void operator-=(Graph& g1, Graph& g2); // subtraction operator
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
