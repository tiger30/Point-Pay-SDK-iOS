//
//  PLVPaymentResult.h
//  PaylevenSDK
//
//  Created by Alexei Kuznetsov on 21/10/14.
//  Copyright (c) 2014 payleven Holding GmbH. All rights reserved.
//

@import Foundation;

/** 
 @brief Payment result state. Indicates the payment state as Approved, Declined or Cancelled
 */
typedef NS_ENUM(NSInteger, PLVPaymentResultState) {
    
    /** 
     Approved. 
     */
    PLVPaymentResultStateApproved,
    
    /** 
     Declined. 
     */
    PLVPaymentResultStateDeclined,
    
    /** 
     Cancelled. 
     */
    PLVPaymentResultStateCancelled
};

/** 
 @brief POS entry mode constants. Indicates point of sale type.
 */
typedef NS_ENUM(NSInteger, PLVPointOfSaleEntryMode) {
    
    /** 
     Unknown mode. 
     */
    PLVPointOfSaleEntryModeUnknown,
    
    /** 
     ICC (chip) mode. 
     */
    PLVPointOfSaleEntryModeIntegratedCircuitCard,
    
    /**
     Contactless (NFC) mode.
     */
    PLVPointOfSaleEntryModeContactless,
    
    /** 
     Swipe mode. 
     */
    PLVPointOfSaleEntryModeMagneticStripeReader,
    
    /** 
     Manual mode. 
     */
    PLVPointOfSaleEntryModePANKeyEntry
};

/** 
 @brief Cardholder verification method constants.
 */
typedef NS_ENUM(NSInteger, PLVCardholderVerificationMethod) {
    
    /** 
     Could not detect CVM or CVM is unknown. 
     */
    PLVCardholderVerificationMethodUnknown,
    
    /** 
     No CVM required. 
     */
    PLVCardholderVerificationMethodNone,
    
    /** 
     PIN verification. 
     */
    PLVCardholderVerificationMethodPIN,
    
    /** 
     Signature verification. 
     */
    PLVCardholderVerificationMethodSignature,
    
    /** 
     PIN and signature verification .
     */
    PLVCardholderVerificationMethodPINSignature,
};

@class PLVReceiptGenerator, PLVPaymentResultAdditionalData;

/** 
 @brief PLVPaymentResult class represents payment results. 
 */
@interface PLVPaymentResult : NSObject
/** 
 Mandatory unique identifier (e.g order number) of the payment request.
 The ID can be any set of alphanumeric characters [A-Z, a-z, 0-9].
 This payment identifier must be included in receipts and will be reflected on payleven's receipt images. Please retain this identifier for your records and for further reference (e.g Refund).
 */
@property(nonatomic, readonly, copy) NSString *paymentIdentifier;
@property(nonatomic, readonly, copy) NSString *identifier DEPRECATED_MSG_ATTRIBUTE("use paymentIdentifier");

/** 
 State of payment.
 */
@property(nonatomic, readonly, assign) PLVPaymentResultState paymentState;
@property(nonatomic, readonly, assign) PLVPaymentResultState state DEPRECATED_MSG_ATTRIBUTE("use paymentState");

/** 
 Amount to be charged in a decimal format, which must be at least one major currency unit (e.g 1.00 Euro) and cannot be negative or zero.
 */
@property(nonatomic, readonly, copy) NSDecimalNumber *paymentAmount;
@property(nonatomic, readonly, copy) NSDecimalNumber *amount DEPRECATED_MSG_ATTRIBUTE("use paymentAmount");

/** 
 Three-letter alphabetical code according to ISO 4217 representing the payment's currency that must match the merchant country's local currency.
 Supported currencies are EUR, GBP and PLN.
 */
@property(nonatomic, readonly, copy) NSString *paymentCurrency;
@property(nonatomic, readonly, copy) NSString *currency DEPRECATED_MSG_ATTRIBUTE("use paymentCurrency");

/** 
 Date representing the date and time when the payment was requested.
 */
@property(nonatomic, readonly, strong) NSDate *paymentDate;
@property(nonatomic, readonly, strong) NSDate *date DEPRECATED_MSG_ATTRIBUTE("use paymentDate");

/** Authorization code generated by the issuing bank of a payer’s payment card, in order to validate a payment card when it is approved or declined in the sale of a good or service. */
@property(nonatomic, readonly, copy) NSString *authorizationCode;

/** 
 URL of the stored signature image if the payment card requires the payer's signature as a payment verification method. Returns nil if not applicable.
 */
@property(nonatomic, readonly, strong) NSURL *signatureImageURL;
/** 
 Serial number of the payleven terminal facilitating the payment.
 */
@property (nonatomic, readonly, copy) NSString *terminalIdentifier;
@property (nonatomic, readonly, copy) NSString *terminalId DEPRECATED_MSG_ATTRIBUTE("use terminalIdentifier");

/** 
 payleven merchant account identifier that executed the payment attempt.
 */
@property (nonatomic, readonly, copy) NSString *merchantIdentifier;
@property (nonatomic, readonly, copy) NSString *merchantId DEPRECATED_MSG_ATTRIBUTE("use merchantIdentifier");

/** 
 Returns an instance of PLVReceiptGenerator, which generates a receipt image for the payment.
 NOTE: Receipt image must be extended with the merchant's name, address and respective receipt identifier.
 */
@property(nonatomic, readonly, strong) PLVReceiptGenerator *receiptGenerator;
/** 
 Returns additional response data of the payment attempt. Returns nil if integrator account is not enabled.
 If you would like to create your own receipts, you will require these details. Please contact developer@payleven.com.
 */
@property(nonatomic, readonly, strong) PLVPaymentResultAdditionalData *additionalData;

@end
