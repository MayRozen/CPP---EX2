בס"ד

ID: 212051007
Mail: mayrozen45@gmail.com

מטלה 2 - תכנות מערכות 2:
במטלה זו התמקדנו ביצירת אופרטורים על גרפים. 
אתחיל קודם בלפרט על הבנאים בהם השתמשתי במטלה זו:

בנאי ריק אשר מגדיר את כמות קודקודי הגרף לאפס כ - defuolt.

        Graph(){
            this->numVertices = 0;
        }

בנאי שמקבל מטריצת שכנויות ובונה על בסיסה את הגרף.

        // Constructor taking the adjacency matrix
        Graph(const std::vector<std::vector<int>>& Mat) : numVertices(Mat.size()), adjMatrix(Mat) {}

בנאי מעתיק (בו נשתמש בהמשך עבור ++ ו - -- ).

        // Copy constructor
        Graph(const Graph& other);

destructor - עלינו "לפרק" את מה שבנינו ונבצע זאת על ידי ה - destructor.

        // Destructor
        ~Graph(){
            this->adjMatrix.clear();
        }

כעת אפרט על כל אופרטור בקצרה, על המימוש שלו וכיצד בחרתי לגשת למשתנים או להחזירם מהאופרטור.
נשים לב תחילה שבקובץ hpp כלל האופרטורים מוצהרים עם "friend". זאת על מנת שנוכל לגשת לשדות של הגרף באופן ישיר דרך אותה מחלקה בה מימשנו את האופרטורים - Graph.cpp.
בנוסף, נשים לב לערכי ההחזרה של כל פונקציה. ישנן פונקציות שבהן עבדנו ישירות על ה - reference של הגרף ולכן אין צורך להחזיר אותו. השינוי שבו (עקב האופרטור שהפעלנו עליו) יהיה שמור בגרף המקור ומשם נוכל לגשת לגרף המעודכן.
כהמשך לכך, במקרים אלו, קלט הפונקציה הוא ה - reference של הגרף ולא העתק שלו.

כעת נפרט על כל פונקציה:

        אופרטורים חשבוניים
בפונקציה זו ביצענו חיבור בין שני גרפים. כלומר, בין כל שתי צלעות בהתאם לקודקודי הגרפים. כל זאת בהתאם למטריצת השכנויות מהן שני הגרפים מורכבים.

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

        אופרטורי השוואה

על מנת לבדוק האם גרף אחד גדול מגרף אחר עלינו לבדוק האם הגרף הראשון (הקטן יותר) מוכל בשני. אם אף גרף לא מוכל ממש בשני והגרפים לא שווים, נבדוק האם כמות הצלעות בגרף הגדול גדולה או שווה מכמות הצלעות בגרף השני. אם כן - נחזיר שגרף זה אכן גדול יותר.

        friend bool operator>(Graph g1, Graph g2);

אופרטור גדול שווה הבודק האם גרף 1 גדול או שווה לגרף 2.

        friend bool operator>=(Graph g1, Graph g2);

אופרטור קטן.

        friend bool operator<(Graph g1, Graph g2);
אופרטור קטן או שווה.

        friend bool operator<=(Graph g1, Graph g2);

אופרטור שווה - בודק האם שני הגרפים זהים לחלוטין.

        friend bool operator==(const Graph& g1, const Graph& g2);

אופרטור שונה - בודק האם הגרפים שונים.

        friend bool operator!=(const Graph& g1, const Graph& g2);

        הגדלה ב-1 (++) והקטנה ב-1 (--) לפני ואחרי המספר

על מנת לבצע הוספה לפני הגרף, נוכל פשוט לקחת את הגרף ולהעלות כל צלע בו (כל איבר במטריצת השכוניות) באחד.

        friend Graph& operator++(Graph &g); //++n

על מנת לבצע הוספה לאחר הגרף, עלינו לבצע תחילה העתקה עמוקה לגרף (אותה ביצעתי על ידי בנאי מעתיק אשר מופיע בתחילת הקובץ Graph.hpp) ועליו לבצע את ההוספה. כמו כן, הגרף המועתק זה יהיה הגרף שיוחזר.

        friend const Graph operator++(Graph &g, int); // n++

הקטנת כל איברי הגרף באחד לפני הגרף.

        friend Graph& operator--(Graph &g); //--n

הקטנת כל איברי הגרף באחד אחרי הגרף - באופן זהה להוספה -> יתקיים בעזרת בנאי מעתיק והחזרת הגרף המועתק.

        friend const Graph operator--(Graph &g, int); // n--

        הכפלה וחילוק בסקלר

ביצוע הכפלת כל איבר מהגרף בסקלר c. זאת על ידי מעבר על מטריצת השכנויות של הגרף והכפלת כל ערך בקבוע c.

        friend void operator*(Graph& g, int c); // Multiplication by a scalar

אופרטור מקוצר להכפלה בסקלר c.

        friend void operator*=(Graph &g, int c); // Multiply the graph by int

אופרטור מקוצר לחילוק בסקלר c.

        friend void operator/=(Graph &g, int c); // Dividing the graph by int

        הכפלה בין שני גרפים

מתבצע על ידי הכפלה בין שתי המטריצות מהן כל אחד מהגרפים מורכב. נשים לב שאת התוצאה אנחנו מכניסים לתוך ה - reference של גרף 1.

        friend Graph operator*(const Graph& g1, const Graph& g2); // Graph Multiplication

        אופרטור הדפסה
אופרטור המאפשר הדפסה של הגרף על ידי >>.

        friend std::ostream& operator<<(std::ostream &os, const Graph& g); // Print Graph
