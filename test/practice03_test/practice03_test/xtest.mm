//
//  xtest.m
//  xtest
//
//  Created by Eli Dollinger on 2/9/25.
//

#import <XCTest/XCTest.h>
#import "practice03_test.cpp"
#import <vector>

@interface xtest : XCTestCase

@end

@implementation xtest

- (void)setUp
{
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown
{
    // Put teardown code here. This method is called after the invocation of each test method in the class.
}

- (void)testSumRange
{
    int result = MathUtils::sumRange(1,5);
    XCTAssertEqual(result, 15, "The sum should be 15");
    
    result = MathUtils::sumRange(-3,-3);
    XCTAssertEqual(result, -3, "The sum should be -3");
    
    result = MathUtils::sumRange(2,3);
    XCTAssertEqual(result, 5, "The sum should be .");
}

- (void)testContainsNegative
{
    std::vector<int> testNeg = {2, 3, -1, 8};
    bool containsNegative = MathUtils::containsNegative(testNeg);
    XCTAssertTrue(containsNegative, "The vector should contain a negative number");
    
    testNeg = {0, 3, 2, 5};
    containsNegative = MathUtils::containsNegative(testNeg);
    XCTAssertFalse(containsNegative, "The vector should contain no negative numbers");
    
    testNeg = {-2, -3, -5, 2};
    containsNegative = MathUtils::containsNegative(testNeg);
    XCTAssertTrue(containsNegative, "The vector should contain a negative number");
}

- (void)testFindMax
{
    std::vector<int> testMax = {5, 4, 3, 2};
    int max = MathUtils::findMax(testMax);
    XCTAssertEqual(max, 5, "The max value should be 5");
    
    testMax = {5, 20, -7, 29};
    max = MathUtils::findMax(testMax);
    XCTAssertEqual(max, 29, "The max value should be 29");
    
    testMax = {5, 21, 20, 9};
    max= MathUtils::findMax(testMax);
    XCTAssertEqual(max, 21, "The max value should be 21");
    std::vector<int> emptyVector;
    max = MathUtils::findMax(emptyVector);
    XCTAssertEqual(max, INT_MIN, "The vector is empty");
}

@end
