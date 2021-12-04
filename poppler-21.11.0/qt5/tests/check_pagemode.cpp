#include <QtTest/QtTest>

#include <poppler-qt5.h>

class TestPageMode : public QObject
{
    Q_OBJECT
public:
    explicit TestPageMode(QObject *parent = nullptr) : QObject(parent) { }
private slots:
    void checkNone();
    void checkFullScreen();
    void checkAttachments();
    void checkThumbs();
    void checkOC();
};

void TestPageMode::checkNone()
{
    Poppler::Document *doc;
    doc = Poppler::Document::load(TESTDATADIR "/unittestcases/UseNone.pdf");
    QVERIFY(doc);

    QCOMPARE(doc->pageMode(), Poppler::Document::UseNone);

    delete doc;
}

void TestPageMode::checkFullScreen()
{
    Poppler::Document *doc;
    doc = Poppler::Document::load(TESTDATADIR "/unittestcases/FullScreen.pdf");
    QVERIFY(doc);

    QCOMPARE(doc->pageMode(), Poppler::Document::FullScreen);

    delete doc;
}

void TestPageMode::checkAttachments()
{
    Poppler::Document *doc;
    doc = Poppler::Document::load(TESTDATADIR "/unittestcases/UseAttachments.pdf");
    QVERIFY(doc);

    QCOMPARE(doc->pageMode(), Poppler::Document::UseAttach);

    delete doc;
}

void TestPageMode::checkThumbs()
{
    Poppler::Document *doc;
    doc = Poppler::Document::load(TESTDATADIR "/unittestcases/UseThumbs.pdf");
    QVERIFY(doc);

    QCOMPARE(doc->pageMode(), Poppler::Document::UseThumbs);

    delete doc;
}

void TestPageMode::checkOC()
{
    Poppler::Document *doc;
    doc = Poppler::Document::load(TESTDATADIR "/unittestcases/UseOC.pdf");
    QVERIFY(doc);

    QCOMPARE(doc->pageMode(), Poppler::Document::UseOC);

    delete doc;
}

QTEST_GUILESS_MAIN(TestPageMode)
#include "check_pagemode.moc"
