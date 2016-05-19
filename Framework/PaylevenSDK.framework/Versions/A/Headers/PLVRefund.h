//
//  PLVRefund.h
//  PaylevenSDK
//
//  Created by Bob Obi on 7/23/15.
//  Copyright (c) 2015 payleven Holding GmbH. All rights reserved.
//

@import Foundation;
/**
 @brief PLVRefund represents a refund object. That contans the merchantIdentifier which is the merchant Id
 refundIdentifier which represents the refund Id provided in PLVRefundRequest. The refundedAmount is a 
 NSDecimalNumber of the refundedAmount. The paymentAmount is an NSDecimalNumber that holds the original
 Payment given in the PLVPaymentRequest at payment time. NSDecimalNumber remainingAmount is residual amount
 in case of partial refunds. The currency is Three-letter ISO 4217 currency code. For example, EUR. The
 refundDate represents the date of execution. The refundDescription represents the refund desc.  
  */
@interface PLVRefund : NSObject<NSCopying>
/**
 * payleven merchant account identifier that executed the refund request.
 */
@property(nonatomic, readonly) NSString *merchantIdentifier;
/**
 * Mandatory unique identifier of the refund request generated by the integrator on behalf of the merchant(s).
 The ID can be any set of alphanumeric characters [A-Z, a-z, 0-9].
 Please retain this identifier for your records.
 */
@property(nonatomic, readonly) NSString *refundIdentifier;
/**
 * Unique identifier referring to the initial sale payment to be refunded.
 Please retain this identifier for your records and for further reference (e.g Refund).
 */
@property(nonatomic, readonly) NSString *paymentIdentifier;
/**
 * Amount that has been requested to be refunded in a decimal format, which must be at least two minor currency units (e.g 0.02 Euro) and cannot be negative or zero.
 */
@property(nonatomic, readonly) NSDecimalNumber *refundAmount;
@property(nonatomic, readonly) NSDecimalNumber *refundedAmount DEPRECATED_MSG_ATTRIBUTE("use refundAmount");

/**
 * Amount charged with the initial sale payment in a decimal format.
 */
@property(nonatomic, readonly) NSDecimalNumber *paymentAmount;
/**
 * Amount of the remaining transaction balance in a decimal format.
 */
@property(nonatomic, readonly) NSDecimalNumber *refundableAmount;
@property(nonatomic, readonly) NSDecimalNumber *remainingAmount DEPRECATED_MSG_ATTRIBUTE("use refundableAmount");

/**
 * Three-letter alphabetic code according to ISO 4217 representing the refund's currency. Currency must not deviate from initial sale payment's currency. Supported currencies are EUR, GBP and PLN.
 */
@property(nonatomic, readonly) NSString *refundCurrency;
@property(nonatomic, readonly) NSString *currency DEPRECATED_MSG_ATTRIBUTE("use refundCurrency");

/**
 * Date representing the date and time when the refund was requested.
 */
@property(nonatomic, readonly) NSDate *refundDate;
/**
 * Optional description provided by the merchant (max 140 characters).
 */
@property(nonatomic, readonly) NSString *refundDescription;

@end
